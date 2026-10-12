/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x404620; label: FUN_00404620
 */

void FUN_00404620(int param_1,int param_2)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(int *)(*(int *)(param_1 + 0xcc0) + 0x84) = param_1;
  *(undefined1 *)(*(int *)(param_1 + 0xcc0) + 0x7d) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0xcc0) + 0x7e) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0xcc0) + 0x80) = 0;
  *(float *)(*(int *)(param_1 + 0xcc0) + 0x70) =
       (float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x5a) >> 1] * 4.0;
  *(float *)(*(int *)(param_1 + 0xcc0) + 0x74) = *(float *)(param_1 + 0x6c) * 0.5;
  *(float *)(*(int *)(param_1 + 0xcc0) + 0x78) =
       (float)(&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x5a) + 0x4000) >> 1 & 0x7fff] * 4.0;
  FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f000000,0);
  iVar5 = *(int *)(param_1 + 0xcc0);
  *(undefined4 *)(iVar5 + 100) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(iVar5 + 0x68) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(iVar5 + 0x6c) = *(undefined4 *)(param_1 + 0x88);
  if ((((*(byte *)(param_1 + 0xe24) & 8) != 0) &&
      (iVar5 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x112), iVar5 != -1)) &&
     (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar5 * 4) != 0)) {
    iVar3 = iVar5 * 0x40 + 0x834 + param_1;
    iVar4 = *(int *)(param_1 + 0xcc0);
    *(undefined4 *)(iVar4 + 100) = *(undefined4 *)(iVar5 * 0x40 + 0x834 + param_1);
    *(undefined4 *)(iVar4 + 0x68) = *(undefined4 *)(iVar3 + 4);
    *(undefined4 *)(iVar4 + 0x6c) = *(undefined4 *)(iVar3 + 8);
  }
  if ((*(char *)(*(int *)(param_1 + 0xcc0) + 0x7c) == '\0') && (param_2 == 2)) {
    FUN_00403f60(PTR_DAT_00802c54,param_1,1);
    iVar5 = *(int *)(param_1 + 0xcc0);
    if (*(char *)(iVar5 + 0x7c) == '\0') {
      *(float *)(iVar5 + 8 + (uint)*(byte *)(iVar5 + 0x7c) * 0x14) =
           *(float *)(param_1 + 0x80) +
           (float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x5a) >> 1] * 2.0;
      *(undefined4 *)
       (*(int *)(param_1 + 0xcc0) + 0xc + (uint)*(byte *)(*(int *)(param_1 + 0xcc0) + 0x7c) * 0x14)
           = *(undefined4 *)(param_1 + 0x84);
      *(float *)(*(int *)(param_1 + 0xcc0) + 0x10 +
                (uint)*(byte *)(*(int *)(param_1 + 0xcc0) + 0x7c) * 0x14) =
           (float)(&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x5a) + 0x4000) >> 1 & 0x7fff] * 2.0 +
           *(float *)(param_1 + 0x88);
      piVar2 = (int *)(*(int *)(param_1 + 0xcc0) +
                      (uint)*(byte *)(*(int *)(param_1 + 0xcc0) + 0x7c) * 0x14);
      *piVar2 = (int)(piVar2 + 2);
      *(undefined1 *)
       (*(int *)(param_1 + 0xcc0) + 4 + (uint)*(byte *)(*(int *)(param_1 + 0xcc0) + 0x7c) * 0x14) =
           3;
      *(undefined1 *)
       (*(int *)(param_1 + 0xcc0) + 5 + (uint)*(byte *)(*(int *)(param_1 + 0xcc0) + 0x7c) * 0x14) =
           0;
      pcVar1 = (char *)(*(int *)(param_1 + 0xcc0) + 0x7c);
      *pcVar1 = *pcVar1 + '\x01';
    }
  }
  return;
}

