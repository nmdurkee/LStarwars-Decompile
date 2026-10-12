/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a5dd0; label: FUN_004a5dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

ushort FUN_004a5dd0(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_4c [3];
  undefined4 local_40 [16];
  
  if (param_2 == (undefined4 *)0x0) {
    param_2 = local_4c;
  }
  if (*(char *)(param_1 + 0x107a) == '\x04') {
    puVar3 = (undefined4 *)(param_1 + 0xb8);
    puVar4 = local_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_005b5060(local_40,0x8000);
    FUN_005b3200(param_2,&DAT_0080250c,local_40);
    return *(ushort *)(param_1 + 0x58);
  }
  if (((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x80) == 0)) {
    uVar1 = *(ushort *)(param_1 + 0x5a);
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x58);
    if (*(char *)(param_1 + 0x7b5) == '*') {
      if (0.25 <= 1.0 - *(float *)(param_1 + 0x77c) / *(float *)(param_1 + 0x784)) {
        uVar1 = uVar1 + 0x8000;
      }
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = (&DAT_029899a0)[uVar1 >> 1];
    param_2[1] = 0;
    param_2[2] = (&DAT_029899a0)[(int)(uVar1 + 0x4000) >> 1 & 0x7fff];
  }
  return uVar1;
}

