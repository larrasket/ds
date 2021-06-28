#include <climits>
#define null nullptr
using namespace std;
template<class t, class t2> 
class pq
  {
  	struct h {
  		t data;
  		t2 priority;
  	};
  	h *harr; 
  	int capacity;
  	int heap_size;
  	      

    t extractMin()
    {
    	if (heap_size <= 0)
    		return null;
    	if (heap_size == 1)
    	{
    		heap_size--;
    		return harr[0].data;
    	}
    	t root = harr[0].data;
    	harr[0] = harr[heap_size-1];
    	heap_size--;
    	MinHeapify(0);
    	return root;
    }
  public:
  void swap(h &x, h &y) {
  	t tmp1 = x.data;
       	t2 tmp2 = x.priority;
  	x.data = y.data; x.priority =y.priority;
  	y.data = tmp1; y.priority = tmp2;
  
  }
  pq(int cap)
  {
  	heap_size = 0;
  	capacity = cap;
  	harr = new h[cap];
  }
    	int parent(int i) { return (i-1)/2; }
    	int left(int i) { return (2*i + 1); }
    	int right(int i) { return (2*i + 2); }
    	t2 getMin() { return harr[0].priority; };
	int size () { return heap_size; }
  void MinHeapify(int i)
    {
    	int l = left(i);
    	int r = right(i);
    	int smallest = i;
    	if (l < heap_size && harr[l].priority < harr[i].priority)
    		smallest = l;
    	if (r < heap_size && harr[r].priority < harr[smallest].priority)
    		smallest = r;
    	if (smallest != i)
      	{
      		swap(harr[i], harr[smallest]);
      		MinHeapify(smallest);
    	}
    }
    void enqueue(t k, t2 p)
    {
    	if (heap_size == capacity)
    	{
    		return;
    	}
    
    	heap_size++;
    	int i = heap_size - 1;
    	harr[i].data = k;
    	harr[i].priority = p;
    	while (i != 0 && harr[parent(i)].priority > harr[i].priority)
    	{
    	swap(harr[i], harr[parent(i)]);
    	i = parent(i);
    	}
    }
    void changeweight(int i, int new_val)
    {
    	harr[i].priority = new_val;
    	while (i != 0 && harr[parent(i)].priority < harr[i].priority)
    	{
    	swap(harr[i], harr[parent(i)]);
    	i = parent(i);
    	}
    }
    t back() { return harr[0].data; }
    
    t dequeue()
    {	
    return	extractMin();
    } 
    
/*    void requeue()
      {
      	changeweight(heap_size-1, INT_MIN);
  	heap_size--;
      } 
      t front () {
    	  return harr[0].data;
      }
      t back () {
    	  return harr[heap_size-1].data;
    }*/
    
  };
/*int main() {
  	pq <char,int>l(3) ;
  	l.enqueue('f',5);
  	l.enqueue('t',9);
  	l.enqueue('o',2);
  	cout << l.dequeue();
  	cout << l.dequeue();
  	cout << l.dequeue();
  
}*/
