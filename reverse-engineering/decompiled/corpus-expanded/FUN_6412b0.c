/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x6412b0; label: FUN_006412b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006412b0(undefined4 param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *param_2 + 3 & 0xfffffffc;
  *param_2 = uVar2;
  FUN_006354a0(uVar2);
  uVar1 = FUN_00641020(param_1,uVar2);
  *(undefined4 *)(uVar2 + 0x560) = uVar1;
  DAT_0291396c = uVar2;
  *param_2 = *param_2 + 0x564;
  return uVar2;
}

