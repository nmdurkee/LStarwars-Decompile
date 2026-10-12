/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x580f50; label: FUN_00580f50
 */

undefined4 FUN_00580f50(void)

{
  uint uVar1;
  bool bVar2;
  int *in_EAX;
  uint uVar3;
  int iVar4;
  
  bVar2 = false;
  uVar3 = FUN_00569c60();
  if (*(short *)(*in_EAX + 0x66) == -1) {
    FUN_00547930(0x28,in_EAX + 0x22,0,0);
  }
  else {
    FUN_005478a0((int)*(short *)(*in_EAX + 0x66));
  }
  if (((*(ushort *)(in_EAX + 0x3e) & 0x800) != 0) &&
     (iVar4 = FUN_0055abd0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),PTR_DAT_00802c54), iVar4 != 0)
     ) {
    return 1;
  }
  iVar4 = FUN_0056a1a0(PTR_DAT_00802c54,(int)*(short *)((int)in_EAX + 0xfa));
  if (iVar4 != 0) {
    uVar1 = *(uint *)(iVar4 + 0x98);
    if ((uVar1 & 0x8000) != 0) {
      if (((((uVar3 & 1) != 0) && (in_EAX[1] != 0)) && ((uVar1 & 0x80000) != 0)) &&
         (0.0 < *(float *)(*(int *)(*(int *)(in_EAX[1] + 0x54) + 0x24) + 0x28))) {
        return 0;
      }
      if (((in_EAX[1] != 0) && ((uVar1 & 0x80000) != 0)) && (*(int *)(in_EAX[1] + 0xcd0) == 0)) {
        return 0;
      }
      iVar4 = FUN_00567800(iVar4,1,3,*(undefined1 *)(*in_EAX + 0x3c),0,1);
      if (iVar4 == 0) {
        return 1;
      }
      if (in_EAX[1] == 0) {
        return 1;
      }
      FUN_0054a850(**(undefined4 **)(in_EAX[1] + 0xca4),0x3ecccccd,0);
      return 1;
    }
    bVar2 = true;
  }
  if (((char)in_EAX[0x41] != -1) &&
     (((*(uint *)(&DAT_008034cc + (char)in_EAX[0x41] * 0xc) & 0x1800) != 0 || (bVar2)))) {
    FUN_00547930(0x29,in_EAX + 0x22,0,0);
    FUN_0057fc80();
    iVar4 = in_EAX[1];
    if ((iVar4 != 0) && ((*(byte *)(iVar4 + 0x1fc) & 0x80) != 0)) {
      FUN_0054a850(**(undefined4 **)(iVar4 + 0xca4),0x3ecccccd,0);
      FUN_00549f10();
    }
  }
  return 0;
}

