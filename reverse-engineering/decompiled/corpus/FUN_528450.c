/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x528450; label: FUN_00528450
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00528450(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_EDI;
  float10 fVar2;
  
  iVar1 = 0;
  if ((unaff_EDI != -1) && (iVar1 = FUN_004f1440(DAT_009238e4 + 0x3719c), iVar1 != 0)) {
    FUN_004f1410(DAT_009238e4 + 0x3719c,iVar1);
    FUN_004f1310(DAT_009238e4 + 0x371a4,iVar1);
    *(short *)(iVar1 + 0x58) = (short)unaff_EDI;
    *(undefined1 *)(iVar1 + 0x5a) = 0;
    *(undefined1 *)(iVar1 + 0x5b) = DAT_00801c5d;
    *(undefined1 *)(iVar1 + 0x5c) = DAT_00801c5e;
    *(undefined4 *)(iVar1 + 0x60) = _DAT_00801c60;
    *(undefined4 *)(iVar1 + 100) = _DAT_00801c64;
    *(undefined4 *)(iVar1 + 0x98) = _DAT_00923870;
    if (DAT_009238c8 == (code *)0x0) {
      fVar2 = (float10)1;
    }
    else {
      fVar2 = (float10)(*DAT_009238c8)();
    }
    *(float *)(iVar1 + 0x9c) = (float)fVar2;
    if (DAT_009238cc == (code *)0x0) {
      fVar2 = (float10)1;
    }
    else {
      fVar2 = (float10)(*DAT_009238cc)();
    }
    *(float *)(iVar1 + 0xa0) = (float)fVar2;
    if (DAT_009238d0 == (code *)0x0) {
      fVar2 = (float10)1;
    }
    else {
      fVar2 = (float10)(*DAT_009238d0)();
    }
    *(float *)(iVar1 + 0xa4) = (float)fVar2;
    if (DAT_009238d4 == (code *)0x0) {
      fVar2 = (float10)1;
    }
    else {
      fVar2 = (float10)(*DAT_009238d4)();
    }
    *(float *)(iVar1 + 0xa8) = (float)fVar2;
    *(undefined1 *)(iVar1 + 0x8c) = DAT_00801c5c;
    *(undefined1 *)(iVar1 + 0x8d) = DAT_00922264;
    *(undefined1 *)(iVar1 + 0x8e) = DAT_00922265;
    *(undefined4 *)(iVar1 + 0x90) = _DAT_00923868;
    *(undefined4 *)(iVar1 + 0x94) = _DAT_0092386c;
    if (param_1 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar1 + 0x28) = *param_1;
      *(undefined4 *)(iVar1 + 0x2c) = param_1[1];
      *(undefined4 *)(iVar1 + 0x30) = param_1[2];
      *(undefined4 *)(iVar1 + 0x34) = param_2;
    }
  }
  return iVar1;
}

