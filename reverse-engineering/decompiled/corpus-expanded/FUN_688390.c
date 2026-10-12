/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x688390; label: FUN_00688390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00688390(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = DAT_02962010;
  if (DAT_02923194 != -1) {
    uVar1 = *(undefined4 *)(param_2 + 0x54);
    (&DAT_029300dc)[DAT_02962010 * 0xb5] = uVar1;
    if ((&DAT_029300d8)[iVar2 * 0xb5] != -1) {
      FUN_0067c7e0((&DAT_029300d8)[iVar2 * 0xb5],uVar1,(&DAT_029300e0)[iVar2 * 0xb5],
                   (&DAT_029300e4)[iVar2 * 0xb5]);
      return;
    }
  }
  return;
}

