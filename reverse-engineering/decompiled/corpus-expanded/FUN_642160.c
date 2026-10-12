/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x642160; label: FUN_00642160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00642160(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_88;
  undefined1 auStack_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_88;
  puVar1 = (undefined4 *)FUN_00633440(0x20,1);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[6] = 0;
    puVar1[7] = 0;
    *puVar1 = &PTR_FUN_0076bd20;
    puVar1[4] = *(undefined4 *)(in_ECX + 0x10);
    puVar1[5] = *(undefined4 *)(in_ECX + 0x14);
    puVar1[6] = *(undefined4 *)(in_ECX + 0x18);
    puVar1[7] = *(undefined4 *)(in_ECX + 0x1c);
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    (**(code **)(*param_2 + 4))(param_3,puVar1[4],&local_88,0);
    FUN_004f2740(auStack_84,*(undefined4 *)(in_ECX + 0x14),local_88);
    uVar2 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cf8e0,FUN_00641c70,&LAB_00641d10,2,param_2[4],
                         auStack_84);
    puVar1[1] = uVar2;
    FUN_00618e10(param_1,uVar2);
  }
  __security_check_cookie(local_4 ^ (uint)&local_88);
  return;
}

