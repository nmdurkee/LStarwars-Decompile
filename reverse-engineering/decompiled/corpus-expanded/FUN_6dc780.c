/* Ghidra pseudocode, not original source.
 * ev_d9eb3013c9fda622502628697ce0d7be845892a91a12bfef10a3ae0a3a8d7789
 * Entry: 0x6dc780; label: FUN_006dc780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dc780(uint param_1)

{
  uint uVar1;
  
  uVar1 = __controlfp(0,0);
  __controlfp(uVar1 & ~param_1,0x8001f);
  return;
}

