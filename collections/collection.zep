namespace Collections;

class Collection
{
    protected items;

    public function __construct(array items = [])
    {
        let this->items = items;
    }
}
