Operation         Action        PointerMovement   Wrap-Around  Check
enqueue_at_rear   Expandback    rear + 1          (Forward)    If Size - 1 → go to 0
enqueue_at_front  Expandfront   front - 1         (Backward)   If 0 → go to Size - 1
dequeue_at_front  Shrinkfront   front + 1         (Forward)    If Size - 1 → go to 0
dequeue_at_rear   Shrinkback    rear - 1          (Backward)   If 0 → go to Size - 1




If you are enqueueing and the queue is empty (front == -1), don't do any math. Just set both front and rear to 0.
If you are dequeueing and there is only one element left (front == rear), don't do any math. Just set both front and rear back to -1 to empty it out.

