/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c58a0; label: FUN_006c58a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c58a0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  for (puVar1 = *(undefined4 **)(in_ECX + 0xc); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    for (puVar2 = *(undefined4 **)puVar1[2]; puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      if ((int *)puVar2[3] != (int *)0x0) {
        (**(code **)(*(int *)puVar2[3] + 0x14))(param_1,puVar2,&DAT_0081fd1c,&DAT_0081fd2c);
      }
    }
  }
  return;
}

