/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59cb90; label: FUN_0059cb90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined ** FUN_0059cb90(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  ppuVar2 = &PTR_s_heading_00805438;
  iVar3 = 0;
  do {
    iVar1 = FUN_004f8b10(*ppuVar2,param_1);
    if (iVar1 == 0) {
      return &PTR_s_heading_00805438 + iVar3 * 6;
    }
    ppuVar2 = ppuVar2 + 6;
    iVar3 = iVar3 + 1;
  } while ((int)ppuVar2 < 0x8054b0);
  return (undefined **)0x0;
}

