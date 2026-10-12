/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x404d00; label: FUN_00404d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

