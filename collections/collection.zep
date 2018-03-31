namespace Collections;

use Countable;
use ArrayAccess;
use Iterator;
use JsonSerializable;

class Collection implements Countable, ArrayAccess, Iterator, JsonSerializable
{
    /**
     * Items
     *
     * @var array
     */
    protected items;

    /**
     * Position
     *
     * @var integer
     */
    protected position = 0;

    /**
     * Constructor
     *
     * @param array items Items to collect.
     * @return void
     */
    public function __construct(array items = [])
    {
        let this->items = items;
    }

    /**
     * Create collection
     *
     * @param array items Items to collect.
     * @return Collection
     */
    public static function make(array $items)
    {
        return new static($items);
    }

    /**
     * Return count of items
     *
     * @return integer
     */
    public function count()
    {
        return count(this->items);
    }

    /**
     * Does item exist?
     *
     * @param mixed offset The offset.
     * @return boolean
     */
    public function offsetExists(offset)
    {
        return isset(this->items[offset]);
    }

    /**
     * Get offset
     *
     * @param mixed offset The offset.
     * @return mixed
     */
    public function offsetGet(offset)
    {
        return isset(this->items[offset]) ? this->items[offset] : null;
    }

    /**
     * Set offset
     *
     * @param mixed offset The offset.
     * @param mixed value  The value to set.
     * @return void
     */
    public function offsetSet(offset, value)
    {
        if (is_null(offset)) {
            let this->items[] = value;
        } else {
            let this->items[offset] = value;
        }
    }

    /**
     * Unset offset
     *
     * @param mixed offset The offset.
     * @return void
     */
    public function offsetUnset(offset)
    {
        var items = this->items;
        unset(items[offset]);
        let this->items = items;
    }

    /**
     * Get current item
     *
     * @return mixed
     */
    public function current()
    {
        return this->items[this->position];
    }

    /**
     * Move counter to next item
     *
     * @return void
     */
    public function next()
    {
        let this->position = this->position + 1;
    }

    /**
     * Get key for current item
     *
     * @return mixed
     */
    public function key()
    {
        return this->position;
    }

    /**
     * Move counter back to zero
     *
     * @return void
     */
    public function rewind()
    {
        let this->position = 0;
    }

    /**
     * Is current item valid?
     *
     * @return boolean
     */
    public function valid()
    {
        return isset(this->items[this->position]);
    }

    /**
     * Serialize collection to JSON
     *
     * @return string
     */
    public function jsonSerialize()
    {
        return json_encode(this->items);
    }

    /**
     * Convert collection to JSON
     *
     * @return string
     */
    public function toJson()
    {
        return this->jsonSerialize();
    }

    /**
     * Convert collection to array
     *
     * @return array
     */
    public function toArray()
    {
        return this->items;
    }

    /**
     * Map operation
     *
     * @param mixed callback The callback to use.
     * @return Collection
     */
    public function map(callback)
    {
        return new static(array_map(callback, this->items));
    }

    /**
     * Filter operation
     *
     * @param mixed callback The callback to use.
     * @return Collection
     */
    public function filter(callback)
    {
        return new static(array_filter(this->items, callback));
    }

    /**
     * Reverse filter operation
     *
     * @param mixed callback The callback to use.
     * @return Collection
     */
    public function reject(callback)
    {
        return new static(array_filter(this->items, ~callback));
    }

    /**
     * Reduce operation
     *
     * @param mixed callback The callback to use.
     * @param mixed initial  The initial value.
     * @return mixed
     */
    public function reduce(callback, initial = 0)
    {
        var accumulator = initial;
        var item;
        for item in this->items {
            let accumulator = {callback}(accumulator, item);
        }
        return accumulator;
    }

    /**
     * Apply callback to each item in the collection
     *
     * @param mixed callback The callback to use.
     * @return void
     */
    public function each(callback)
    {
        var item;
        for item in this->items {
            {callback}(item);
        }
    }

    /**
     * Push item to end of collection
     *
     * @param mixed item Item to push.
     * @return Collection
     */
    public function push(item)
    {
        let this->items[] = item;
        return new static(this->items);
    }

    /**
     * Pop item from end of collection
     *
     * @return mixed
     */
    public function pop()
    {
        var items = this->items;
        var response = array_pop(items);
        let this->items = items;
        return response;
    }

    /**
     * Push item to start of collection
     *
     * @param mixed item Item to push.
     * @return Collection
     */
    public function unshift(item)
    {
        var items = this->items;
        array_unshift(items, item);
        let this->items = items;
        return new static(this->items);
    }

    /**
     * Pop item from start of collection
     *
     * @return mixed
     */
    public function shift()
    {
        var items = this->items;
        var response = array_shift(items);
        let this->items = items;
        return response;
    }
}
