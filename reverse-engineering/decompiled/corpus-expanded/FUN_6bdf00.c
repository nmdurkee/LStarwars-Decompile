/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6bdf00; label: FUN_006bdf00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bdf00(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  for (puVar1 = (undefined4 *)**(undefined4 **)(in_ECX + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if ((int *)puVar1[3] != (int *)0x0) {
      (**(code **)(*(int *)puVar1[3] + 0x14))(param_1,puVar1,&DAT_0081fd1c,&DAT_0081fd2c);
    }
  }
  return;
}

