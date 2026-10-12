/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c3a80; label: FUN_006c3a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c3a80(uint param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  int in_ECX;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = param_3;
  if (((*(uint *)(*(int *)(in_ECX + 8) + 0x1c) & param_1) != 0) &&
     (iVar3 = 0, puVar2 = param_4, DAT_0081fa94 != (int *)0x0)) {
    piVar1 = DAT_0081fa94;
    do {
      if (((piVar1[3] == *(int *)(in_ECX + 0xc)) && (piVar1[4] != 0)) &&
         (iVar3 = iVar3 + 1, piVar1[4] == *(int *)(in_ECX + 8))) goto LAB_006c3ac6;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if (iVar3 != 0) {
      puVar2 = param_3;
    }
  }
LAB_006c3ac6:
  *(undefined4 *)(param_2 + 0x28) = *puVar2;
  *(undefined4 *)(param_2 + 0x2c) = puVar2[1];
  *(undefined4 *)(param_2 + 0x30) = puVar2[2];
  *(undefined4 *)(param_2 + 0x34) = puVar2[3];
  return;
}

