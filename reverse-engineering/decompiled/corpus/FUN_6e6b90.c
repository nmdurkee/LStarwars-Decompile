/* Ghidra analysis pseudocode, not original source.
 * ev_05a50d78b1ac39cbc8ac7a43523eae9528fc8f40ae743077c5c3f4eab8d21813
 * Entry: 0x6e6b90; label: FUN_006e6b90
 */

ulonglong FUN_006e6b90(void)

{
  ulonglong uVar1;
  uint uVar2;
  undefined4 in_EDX;
  float fVar3;
  float10 in_ST0;
  uint uStack_20;
  float fStack_1c;
  
  if (DAT_029a9c48 == 0) {
    uVar1 = (ulonglong)ROUND(in_ST0);
    uStack_20 = (uint)uVar1;
    fStack_1c = (float)(uVar1 >> 0x20);
    fVar3 = (float)in_ST0;
    if ((uStack_20 != 0) || (fVar3 = fStack_1c, (uVar1 & 0x7fffffff00000000) != 0)) {
      if ((int)fVar3 < 0) {
        uVar1 = uVar1 + (0x80000000 < (uint)-(float)(in_ST0 - (float10)(longlong)uVar1));
      }
      else {
        uVar2 = (uint)(0x80000000 < (uint)(float)(in_ST0 - (float10)(longlong)uVar1));
        uVar1 = CONCAT44((int)fStack_1c - (uint)(uStack_20 < uVar2),uStack_20 - uVar2);
      }
    }
    return uVar1;
  }
  return CONCAT44(in_EDX,(int)in_ST0);
}

