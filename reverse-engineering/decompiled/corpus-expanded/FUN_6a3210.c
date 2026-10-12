/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a3210; label: FUN_006a3210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006a3210(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x68) + 0xc);
  iVar2 = 0xf;
  do {
    FUN_006a38a0(*puVar3);
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = (**(code **)(PTR_PTR_00817024 + 0xc))(param_1);
  if (iVar2 == 0) {
    if (param_2 != (undefined4 *)0x0) {
      iVar2 = FUN_006b0470(param_1);
      if (iVar2 != 0) {
        return -0x83;
      }
      uVar1 = FUN_006a3e10(param_1 + 4);
      *param_2 = uVar1;
      uVar1 = FUN_006a3db0(param_1 + 4);
      param_2[1] = uVar1;
      param_2[2] = 0;
      param_2[3] = *(undefined4 *)(param_1 + 0x2c);
      param_2[4] = *(undefined4 *)(param_1 + 0x30);
      param_2[5] = *(undefined4 *)(param_1 + 0x34);
      param_2[6] = *(undefined4 *)(param_1 + 0x38);
      param_2[7] = *(undefined4 *)(param_1 + 0x3c);
    }
    iVar2 = 0;
  }
  return iVar2;
}

