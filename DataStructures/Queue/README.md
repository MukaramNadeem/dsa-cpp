# Circular Deque Operations

A **circular deque** (double-ended queue) allows insertion and deletion from both ends using pointer arithmetic with wrap-around logic.

## Operation Reference Table


| Operation          | Action       | Pointer Movement | Wrap-Around Direction | Wrap-Around Check         |
| ------------------ | ------------ | ---------------- | --------------------- | ------------------------- |
| `enqueue_at_rear`  | Expand back  | `rear + 1`       | Forward               | If`Size - 1` → go to `0` |
| `enqueue_at_front` | Expand front | `front - 1`      | Backward              | If`0` → go to `Size - 1` |
| `dequeue_at_front` | Shrink front | `front + 1`      | Forward               | If`Size - 1` → go to `0` |
| `dequeue_at_rear`  | Shrink back  | `rear - 1`       | Backward              | If`0` → go to `Size - 1` |

---

## Special Cases

### Empty Queue  Enqueue

> When the queue is empty (`front == -1`),
> Simply set both pointers:

```
front = 0
rear  = 0
```

### Single Element  Dequeue

> When only one element remains (`front == rear`),
> Simply reset both pointers to empty the queue:

```
front = -1
rear  = -1
```

---
