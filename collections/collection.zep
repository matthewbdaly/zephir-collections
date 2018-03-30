namespace Collections;

use Countable;
use ArrayAccess;

class Collection implements Countable, ArrayAccess
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
        unset(this->items[offset]);
    }
}
