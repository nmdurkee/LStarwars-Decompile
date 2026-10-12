/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x554ff0; label: FUN_00554ff0
 */

undefined4 FUN_00554ff0(float param_1,int param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = (int)param_1;
  if (((*(uint *)((int)param_1 + 0x84) & 0x4000) != 0) && (param_2 != 0x1e)) {
    return 2;
  }
  if (((*(uint *)((int)param_1 + 0x84) & 0x8000) != 0) && (param_2 != 0x1f)) {
    return 2;
  }
  if ((((*(short *)((int)param_1 + 0x7c) != *(short *)((int)param_1 + 0x7e)) ||
       (0.0 < *(float *)((int)param_1 + 0x90))) || (*(int *)((int)param_1 + 0x68) == 0)) ||
     (*(char *)((int)param_1 + 0x89) != -1)) {
    return 0;
  }
  iVar3 = FUN_005a1590(*(int *)((int)param_1 + 0x68));
  if (iVar3 != 2) {
    return 1;
  }
  uVar4 = *(uint *)((int)param_1 + 0x84);
  if (param_2 == 0x1e) {
    if ((uVar4 & 4) == 0) goto LAB_005550b3;
LAB_0055507e:
    iVar3 = FUN_005a0f10(*(undefined4 *)((int)param_1 + 0x68));
    if (iVar3 != 0) {
      return 2;
    }
    uVar4 = *(uint *)((int)param_1 + 0x84);
    param_1 = -*(float *)((int)param_1 + 0x78);
    if (param_2 != 0x1f) goto LAB_005550cc;
LAB_005550a6:
    if ((uVar4 & 2) == 0) {
      uVar4 = uVar4 | 1;
      goto LAB_005550d8;
    }
  }
  else {
    if ((uVar4 & 4) == 0) goto LAB_0055507e;
LAB_005550b3:
    if (*(int *)(*(int *)((int)param_1 + 0x68) + 0xc) == 2) {
      return 2;
    }
    param_1 = *(float *)((int)param_1 + 0x78);
    if (param_2 != 0x1e) goto LAB_005550a6;
LAB_005550cc:
    if ((uVar4 & 2) != 0) {
      uVar4 = uVar4 | 1;
      goto LAB_005550d8;
    }
  }
  uVar4 = uVar4 & 0xfffffffe;
LAB_005550d8:
  *(uint *)(iVar1 + 0x84) = uVar4;
  sVar2 = (short)(0x10000 / (ulonglong)(longlong)(int)(uint)*(byte *)(iVar1 + 0x8b));
  if ((*(byte *)(iVar1 + 0x84) & 1) == 0) {
    *(short *)(iVar1 + 0x7e) = *(short *)(iVar1 + 0x7c) - sVar2;
  }
  else {
    *(short *)(iVar1 + 0x7e) = *(short *)(iVar1 + 0x7c) + sVar2;
  }
  FUN_005a1030(*(undefined4 *)(iVar1 + 0x68),param_1,1);
  *(undefined4 *)(iVar1 + 0x90) = 0x3e800000;
  *(undefined2 *)(iVar1 + 0x80) = *(undefined2 *)(iVar1 + 0x7c);
  return 3;
}

