/* Ghidra pseudocode, not original source.
 * ev_071b5a91353aec3b9b3ca880d0ad8ff1dbba963601d7a5f67d3b8ab6c7f681aa
 * Entry: 0x6ebe0a; label: FUN_006ebe0a
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ebe0a(undefined4 *param_1)

{
  undefined4 *in_EAX;
  
  for (; in_EAX < param_1; in_EAX = in_EAX + 1) {
    if ((code *)*in_EAX != (code *)0x0) {
      (*(code *)*in_EAX)();
    }
  }
  return;
}

