/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cfc70; label: FUN_006cfc70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cfc70(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  float local_110;
  float fStack_10c;
  float fStack_108;
  undefined1 auStack_104 [128];
  undefined1 auStack_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_110;
  puVar1 = (undefined4 *)FUN_00633440();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_0076f85c;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    (**(code **)(*param_2 + 4))(param_3,DAT_02973ac8,&local_110,0);
    FUN_004f2740();
    FUN_004f2740(auStack_104,"%.2f %.2f %.2f",(double)local_110,(double)fStack_10c,
                 (double)fStack_108);
    iVar2 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cf8e0,FUN_006ba4c0,FUN_006c41c0,3,auStack_84,
                         auStack_104);
    puVar1[1] = iVar2;
    uVar3 = FUN_006e6b90();
    uVar4 = FUN_006e6b90();
    uVar5 = FUN_006e6b90();
    *(uint *)(iVar2 + 0x50) = ((uVar3 | 0xffffff00) << 8 | uVar4 & 0xff) << 8 | uVar5 & 0xff;
    FUN_00618e10(param_1,puVar1[1]);
  }
  __security_check_cookie(local_4 ^ (uint)&local_110);
  return;
}

