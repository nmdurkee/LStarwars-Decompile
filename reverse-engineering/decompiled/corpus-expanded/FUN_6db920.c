/* Ghidra pseudocode, not original source.
 * ev_d9eb3013c9fda622502628697ce0d7be845892a91a12bfef10a3ae0a3a8d7789
 * Entry: 0x6db920; label: FUN_006db920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006db920(void)

{
  undefined4 *in_ECX;
  undefined4 extraout_ECX;
  
  *in_ECX = 0xffffffff;
  *(undefined1 *)((int)in_ECX + 0x455) = 1;
  *(undefined1 *)((int)in_ECX + 0x459) = 1;
  FUN_006db0c0();
  return extraout_ECX;
}

