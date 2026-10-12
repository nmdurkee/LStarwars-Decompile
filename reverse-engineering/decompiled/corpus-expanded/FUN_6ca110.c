/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6ca110; label: FUN_006ca110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ca110(undefined4 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int *in_ECX;
  undefined1 auStack_1a4 [4];
  undefined4 uStack_1a0;
  int *piStack_19c;
  undefined1 local_198 [128];
  undefined1 auStack_118 [128];
  undefined1 local_98 [132];
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)auStack_1a4;
  *in_ECX = 0;
  in_ECX[1] = 0;
  puVar1 = (undefined1 *)FUN_004f1f90(param_1,0x2e);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0;
    FUN_004f1f10(local_198,param_1);
    *puVar1 = 0x2e;
    FUN_004f1f10(local_98,puVar1 + 1);
    iVar2 = FUN_006be7a0(local_198);
    *in_ECX = iVar2;
    if (((iVar2 != 0) && ((*(byte *)(iVar2 + 4) & 2) != 0)) && (*(int *)(iVar2 + 0x14) != 0)) {
      iVar2 = (**(code **)(**(int **)(iVar2 + 0x14) + 0x14))(0);
      in_ECX[1] = iVar2;
      while (iVar2 != 0) {
        iVar2 = FUN_006c6a10(&uStack_1a0,in_ECX[1],2,1);
        if (iVar2 != 0) {
          if ((*(byte *)(piStack_19c + 7) & 2) != 0) {
            (**(code **)(*piStack_19c + 4))(uStack_1a0,DAT_02973ac4,auStack_118,0x80);
          }
          iVar2 = FUN_004f8b10(local_98,auStack_118);
          if (iVar2 == 0) break;
        }
        iVar2 = (**(code **)(**(int **)(*in_ECX + 0x14) + 0x14))(in_ECX[1]);
        in_ECX[1] = iVar2;
      }
    }
  }
  __security_check_cookie(local_14 ^ (uint)auStack_1a4);
  return;
}

