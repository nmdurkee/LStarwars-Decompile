/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x579f60; label: FUN_00579f60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00579f60(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  
  if ((DAT_00951bbc < DAT_00951bc0) && (DAT_00951bc8 != 0)) {
    iVar1 = FUN_004f1ff0(param_1);
    iVar2 = DAT_00951bd0;
    if (DAT_00951bcc <= DAT_00951bd0 + 1 + iVar1) {
      return 0;
    }
    *(undefined1 *)(DAT_00951bb8 + DAT_00951bbc * 8) = param_2;
    iVar2 = iVar2 + DAT_00951bc8;
    *(int *)(DAT_00951bb8 + 4 + DAT_00951bbc * 8) = iVar2;
    DAT_00951bbc = DAT_00951bbc + 1;
    _DAT_00951bc4 = _DAT_00951bc4 + 1;
    FUN_004f1f10(iVar2,param_1);
    DAT_00951bd0 = DAT_00951bd0 + 1 + iVar1;
    return 1;
  }
  return 0;
}

