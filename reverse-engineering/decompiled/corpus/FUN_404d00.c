/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x404d00; label: FUN_00404d00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00404d00(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int unaff_ESI;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  FUN_005b3830(local_18,unaff_ESI + 0x70,_DAT_00925018 + _DAT_00925018);
  FUN_005b37d0(local_c,unaff_ESI + 100,local_18);
  iVar3 = FUN_0067b430(unaff_ESI + 100,local_18,0,0x3f800000,0,0x1f);
  if (iVar3 == 0) {
    return false;
  }
  iVar3 = FUN_0067fb40();
  if ((*(char *)(unaff_ESI + 0x7d) == '\0') ||
     (*(byte *)(unaff_ESI + 0x7e) < *(byte *)(unaff_ESI + 0x7c))) {
    piVar1 = (int *)(unaff_ESI + (uint)*(byte *)(unaff_ESI + 0x7e) * 0x14);
    cVar2 = (char)piVar1[1];
    if ((cVar2 != '\0') && (cVar2 != '\x01')) {
      if (cVar2 == '\x02') {
        return *(short *)(*piVar1 + 0x102) != iVar3;
      }
      if (cVar2 != '\x03') {
        return false;
      }
    }
  }
  return true;
}

