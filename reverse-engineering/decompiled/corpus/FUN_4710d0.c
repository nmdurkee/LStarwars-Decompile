/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x4710d0; label: FUN_004710d0
 */

void FUN_004710d0(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x46ec);
  if (iVar1 != 0) {
    puVar3 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"pad_drop");
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 *)(DAT_00879468 + 0x518) = 0;
    }
    else {
      *(undefined4 *)(DAT_00879468 + 0x518) = *puVar3;
      if ((*(int *)(DAT_00879468 + 0x518) != 0) &&
         (*(int *)(*(int *)(DAT_00879468 + 0x518) + 0x34) == 0)) {
        *(undefined4 *)(DAT_00879468 + 0x518) = 0;
      }
    }
    puVar3 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"pad_n");
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 *)(DAT_00879468 + 0x51c) = 0;
    }
    else {
      *(undefined4 *)(DAT_00879468 + 0x51c) = *puVar3;
      if ((*(int *)(DAT_00879468 + 0x51c) != 0) &&
         (*(int *)(*(int *)(DAT_00879468 + 0x51c) + 0x34) == 0)) {
        *(undefined4 *)(DAT_00879468 + 0x51c) = 0;
      }
    }
    puVar3 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"pad_s");
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 *)(DAT_00879468 + 0x520) = 0;
    }
    else {
      *(undefined4 *)(DAT_00879468 + 0x520) = *puVar3;
      if ((*(int *)(DAT_00879468 + 0x520) != 0) &&
         (*(int *)(*(int *)(DAT_00879468 + 0x520) + 0x34) == 0)) {
        *(undefined4 *)(DAT_00879468 + 0x520) = 0;
      }
    }
    puVar3 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"pad_e");
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 *)(DAT_00879468 + 0x524) = 0;
    }
    else {
      *(undefined4 *)(DAT_00879468 + 0x524) = *puVar3;
      if ((*(int *)(DAT_00879468 + 0x524) != 0) &&
         (*(int *)(*(int *)(DAT_00879468 + 0x524) + 0x34) == 0)) {
        *(undefined4 *)(DAT_00879468 + 0x524) = 0;
      }
    }
    puVar3 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"pad_w");
    if (puVar3 == (undefined4 *)0x0) {
      *(undefined4 *)(DAT_00879468 + 0x528) = 0;
    }
    else {
      *(undefined4 *)(DAT_00879468 + 0x528) = *puVar3;
      if ((*(int *)(DAT_00879468 + 0x528) != 0) &&
         (*(int *)(*(int *)(DAT_00879468 + 0x528) + 0x34) == 0)) {
        *(undefined4 *)(DAT_00879468 + 0x528) = 0;
      }
    }
    *(undefined4 *)(iVar1 + 0x490) = *(undefined4 *)(iVar1 + 0x484);
    if ((*(int *)(param_1 + 0x130) == 0) ||
       (*(float *)(*(int *)(param_1 + 0x130) + 0x2814) == 2e+06)) {
      *(undefined4 *)(iVar1 + 0x48c) = *(undefined4 *)(iVar1 + 0x480);
      uVar4 = *(undefined4 *)(iVar1 + 0x488);
    }
    else {
      *(undefined4 *)(iVar1 + 0x48c) = *(undefined4 *)(*(int *)(param_1 + 0x130) + 0x2810);
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x130) + 0x2818);
    }
    *(undefined4 *)(iVar1 + 0x494) = uVar4;
    *(undefined4 *)(iVar1 + 0x540) = 0x49f42400;
    *(undefined4 *)(iVar1 + 0x54c) = 0x49f42400;
    FUN_0062e650(iVar1 + 0x4b4,0xffffffff);
    *(undefined1 *)(iVar1 + 0x558) = 0;
    if (*(int *)(iVar1 + 0x514) != 0) {
      FUN_00470e60();
      *(undefined1 *)(*(int *)(iVar1 + 0x514) + 0x7b5) = 0xff;
    }
    *(undefined4 *)(iVar1 + 0x514) = 0;
    *(undefined4 *)(iVar1 + 0x52c) = 0;
    FUN_00470630();
    *(byte *)(iVar1 + 0x559) = *(byte *)(iVar1 + 0x559) & 0xfa;
    *(undefined4 *)(iVar1 + 0x4ac) = 0;
    *(undefined4 *)(iVar1 + 0x4a8) = 0;
    *(undefined2 *)(iVar1 + 0x55c) = 0;
    *(undefined4 *)(iVar1 + 0x4a4) = 0;
    *(undefined2 *)(iVar1 + 0x55a) = 0;
    *(undefined4 *)(iVar1 + 0x554) = 0;
    *(undefined4 *)(iVar1 + 0x498) = *(undefined4 *)(iVar1 + 0x4a4);
    *(undefined4 *)(iVar1 + 0x49c) = *(undefined4 *)(iVar1 + 0x4a8);
    *(undefined4 *)(iVar1 + 0x4a0) = *(undefined4 *)(iVar1 + 0x4ac);
    if (*(int *)(param_1 + 0x295c) != 0) {
      uVar4 = FUN_005cffb0(iVar1 + 0x4fc);
      uVar2 = FUN_0067c760(uVar4);
      *(undefined2 *)(iVar1 + 0x560) = uVar2;
    }
  }
  return;
}

