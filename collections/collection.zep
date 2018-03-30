namespace Collections;

class Collection
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
}
