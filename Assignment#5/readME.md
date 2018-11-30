# Assignment 5
Parser
Using your own code, implement a parser of your choice to handle for() loop and if-then-else construct. Implementation should handle ambiguity, if any.

# Running Parser
``` python parser.py ```

# Sample Inputs and Outputs
```
If-else case:

Input:
	if e then if e then s else s
Output:
	True

Input:
	if e if e then s else s
Output:
	False

For Loop:

Input:
	for(i=0;i<4;i+){i++}
Output:
	False

Input:
	for(i=0;i<4;i++){stmt}
Output:
	True

```