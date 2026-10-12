/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69b9c0; label: FUN_0069b9c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069b9c0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined1 *in_EAX;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int extraout_EDX;
  int iVar5;
  longlong lVar6;
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  iVar5 = 0;
  bVar1 = false;
  if (in_EAX == (undefined1 *)0x0) {
    lVar6 = FUN_0069b340(local_30,0x10000,0);
    if (lVar6 == -0x80) {
      return -0x80;
    }
    if (((int)((ulonglong)lVar6 >> 0x20) < 1) && (lVar6 < 0)) {
      return -0x84;
    }
    in_EAX = local_30;
  }
  FUN_006a0140(param_1);
  FUN_0069fdb0(param_2);
  iVar2 = FUN_0069ecc0(in_EAX);
  if (iVar2 != 0) {
    iVar2 = in_ECX + 0x78;
    do {
      uVar3 = FUN_0069ed70(in_EAX);
      FUN_0069fb50(iVar2,uVar3);
      FUN_0069f7f0(iVar2,in_EAX);
      iVar4 = FUN_0069fcc0(iVar2,local_20);
      if ((0 < iVar4) && (iVar4 = FUN_006a0760(local_20), iVar4 != 0)) {
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = *(undefined4 *)(in_ECX + 0x1c8);
        }
        *(undefined4 *)(in_ECX + 0x58) = 3;
        iVar2 = FUN_006a0890(param_1,param_2,local_20);
        if (iVar2 != 0) goto LAB_0069bba6;
        goto joined_r0x0069baf3;
      }
      lVar6 = FUN_0069b340(in_EAX,0x10000,0);
      if (lVar6 == -0x80) {
        return -0x80;
      }
      if (lVar6 < 0) {
        return -0x84;
      }
      iVar4 = FUN_0069ecc0(in_EAX);
    } while (iVar4 != 0);
  }
  iVar2 = -0x84;
LAB_0069bba6:
  FUN_006a0180(param_1);
  FUN_006a00b0(param_2);
  *(undefined4 *)(in_ECX + 0x58) = 2;
  return iVar2;
joined_r0x0069baf3:
  while( true ) {
    if (1 < iVar5) {
      return 0;
    }
    iVar2 = FUN_0069fcc0(in_ECX + 0x78,local_20);
    if (iVar2 != 0) break;
    if (1 < iVar5) {
      return 0;
    }
    while( true ) {
      FUN_0069b340(in_EAX,0x10000,0);
      if (extraout_EDX < 0) goto LAB_0069bba1;
      iVar2 = FUN_0069ed70(in_EAX);
      if (*(int *)(in_ECX + 0x1c8) == iVar2) break;
      iVar2 = FUN_0069ecc0();
      if (iVar2 != 0) {
        if (bVar1) goto LAB_0069bba1;
        bVar1 = true;
      }
    }
    FUN_0069f7f0(in_ECX + 0x78,in_EAX);
  }
  if (iVar2 == -1) {
LAB_0069bba1:
    iVar2 = -0x85;
    goto LAB_0069bba6;
  }
  iVar2 = FUN_006a0890(param_1,param_2,local_20);
  if (iVar2 != 0) goto LAB_0069bba6;
  iVar5 = iVar5 + 1;
  goto joined_r0x0069baf3;
}

