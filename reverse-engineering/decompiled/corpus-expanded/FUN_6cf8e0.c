/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cf8e0; label: FUN_006cf8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cf8e0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_2 + 0xc);
  iVar2 = FUN_006caa00();
  DAT_0081fad8 = 0;
  PTR_PTR_0081fa90 = (undefined *)&PTR_PTR_0081faf0;
  FUN_006c58a0(DAT_0081fb00);
  if (iVar2 != 0) {
    *(undefined4 *)(param_2 + 0x28) = DAT_0081fd2c;
    *(undefined4 *)(param_2 + 0x2c) = DAT_0081fd30;
    *(undefined4 *)(param_2 + 0x30) = DAT_0081fd34;
    *(undefined4 *)(param_2 + 0x34) = DAT_0081fd38;
  }
  piVar3 = DAT_0081fcfc;
  if (DAT_0081fcfc != (int *)0x0) {
    while (piVar3[2] != param_1) {
      piVar3 = (int *)*piVar3;
      if (piVar3 == (int *)0x0) {
        return;
      }
    }
    piVar3[3] = iVar1;
  }
  return;
}

