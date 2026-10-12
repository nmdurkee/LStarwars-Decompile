/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6cfa80; label: FUN_006cfa80
 */

void FUN_006cfa80(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  char *pcVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  uint local_28;
  undefined1 auStack_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_28;
  puVar2 = (undefined4 *)FUN_00633440(0x18,1);
  if (puVar2 != (undefined4 *)0x0) {
    uVar3 = *(undefined4 *)(in_ECX + 0x10);
    puVar2[5] = *(undefined4 *)(in_ECX + 0x14);
    puVar2[4] = uVar3;
    *puVar2 = &PTR_LAB_0076b668;
    puVar2[2] = param_2;
    puVar2[3] = param_3;
    (**(code **)(*param_2 + 4))(param_3,DAT_02973ab0,&local_28,0);
    uVar3 = FUN_006267f0(puVar2,&DAT_0081f9a0,&LAB_006cf8e0,param_2[4]);
    puVar2[1] = uVar3;
    FUN_00618e10(param_1,uVar3);
    iVar6 = 0;
    do {
      uVar7 = 1 << ((byte)iVar6 & 0x1f);
      if ((puVar2[5] & uVar7) != 0) {
        FUN_004f2740(auStack_24,&DAT_0075c058,iVar6);
        piVar4 = *(int **)(in_ECX + 0x10);
        iVar1 = *piVar4;
        while (iVar1 != 0) {
          if (piVar4[1] == (uint)((uVar7 & local_28) != 0)) {
            pcVar5 = (char *)*piVar4;
            goto LAB_006cfb55;
          }
          piVar4 = piVar4 + 2;
          iVar1 = *piVar4;
        }
        pcVar5 = "Unknown";
LAB_006cfb55:
        uVar3 = FUN_00626170(puVar2,&DAT_0081f9a0,&LAB_006cf8e0,&LAB_006ba0c0,&LAB_006c3fb0,1,
                             auStack_24,pcVar5,iVar6);
        FUN_0061ee00(puVar2[1],uVar3);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x20);
  }
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}

