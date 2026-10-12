/* Ghidra pseudocode, not original source.
 * ev_bdf1d7790352cc42fa475d7feda1d016092a6193a7278bd37bc81c47b8a4034d
 * Entry: 0x708f9c; label: __87except
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __87except
   
   Library: Visual Studio 2005 Release */

void __87except(int param_1,int *param_2,ushort *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_94;
  undefined1 local_90 [48];
  undefined8 local_60;
  uint local_50;
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)&local_94;
  local_94 = (uint)*param_3;
  iVar1 = *param_2;
  if (iVar1 == 1) {
LAB_00708ff6:
    uVar2 = 8;
LAB_00708ff8:
    iVar1 = __handle_exc(uVar2,param_2 + 6,local_94);
    if (iVar1 == 0) {
      if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
        local_60 = *(undefined8 *)(param_2 + 4);
        local_50 = local_50 & 0xffffffe3 | 3;
      }
      else {
        local_50 = local_50 & 0xfffffffe;
      }
      __raise_exc(local_90,&local_94,uVar2,param_1,param_2 + 2,param_2 + 6);
    }
  }
  else {
    if (iVar1 == 2) {
      uVar2 = 4;
      goto LAB_00708ff8;
    }
    if (iVar1 == 3) {
      uVar2 = 0x11;
      goto LAB_00708ff8;
    }
    if (iVar1 == 4) {
      uVar2 = 0x12;
      goto LAB_00708ff8;
    }
    if (iVar1 == 5) goto LAB_00708ff6;
    if (iVar1 == 7) {
      *param_2 = 1;
    }
    else if (iVar1 == 8) {
      uVar2 = 0x10;
      goto LAB_00708ff8;
    }
  }
  __ctrlfp(local_94,0xffff);
  if ((*param_2 != 8) && (DAT_0082a740 == 0)) {
    iVar1 = FUN_00701fd5(param_2);
    if (iVar1 != 0) goto LAB_00709083;
  }
  __set_errno_from_matherr(*param_2);
LAB_00709083:
  __security_check_cookie(local_14 ^ (uint)&local_94);
  return;
}

