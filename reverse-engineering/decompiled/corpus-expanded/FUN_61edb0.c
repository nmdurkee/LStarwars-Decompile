/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61edb0; label: FUN_0061edb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061edb0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x4c);
  *(int *)(param_1 + 100) = param_2;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    if (puVar1[2] == 0x13) {
      FUN_0061edb0(puVar1,param_2 + 1);
    }
    if (puVar1[2] == 0x11) {
      puVar1[0x1b] = param_2 + 1;
    }
    if (puVar1 == *(undefined4 **)(param_1 + 0x50)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return;
}

