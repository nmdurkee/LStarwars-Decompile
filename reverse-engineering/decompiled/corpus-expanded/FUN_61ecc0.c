/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61ecc0; label: FUN_0061ecc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061ecc0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  if ((*(byte *)(param_4 + 0x78) & 0x40) != 0) {
    if (*(code **)(param_2 + 0x68) != (code *)0x0) {
      (**(code **)(param_2 + 0x68))(param_1,param_2,0);
    }
    if (*(int *)(param_2 + 0x4c) != 0) {
      if ((*(byte *)(param_2 + 0x54) & 1) != 0) {
        FUN_0061eb60(param_2);
        return 0;
      }
      FUN_0061eb20();
    }
  }
  return 0;
}

