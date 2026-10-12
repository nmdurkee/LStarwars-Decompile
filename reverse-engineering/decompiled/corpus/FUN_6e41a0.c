/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e41a0; label: FUN_006e41a0
 */

void FUN_006e41a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x44))
                    (*(int **)(in_ECX + 4),param_1,param_2,param_3,param_4);
  *(int *)(in_ECX + 0x5fc) = iVar1;
  if (iVar1 < 0) {
    if (iVar1 == -0x7789f798) {
      iVar1 = FUN_006e5850();
      if (iVar1 == -0x7789f797) {
        FUN_006e3940(1);
      }
    }
    else {
      SendMessageA(DAT_00924864,0x10,0,0);
    }
  }
  *(undefined4 *)(in_ECX + 0x6f0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x6f4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x6f8) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x6fc) = 0xffffffff;
  return;
}

