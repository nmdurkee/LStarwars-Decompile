/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x60a8e0; label: FUN_0060a8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060a8e0(void)

{
  undefined4 *in_ECX;
  
  FUN_005fb810();
  (&DAT_00986a88)[*(short *)(in_ECX + 0x50)] = 0;
  *in_ECX = &PTR_FUN_007642a4;
  return;
}

