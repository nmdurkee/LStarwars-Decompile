/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x449ee0; label: FUN_00449ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00449ee0(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(PTR_DAT_00802c54 + 0x4688);
  iVar4 = 0;
  puVar2 = PTR_DAT_00802c54;
  if (0 < *(int *)(PTR_DAT_00802c54 + 0x468c)) {
    do {
      if ((((*(ushort *)(iVar3 + 0x68) & 0x40) != 0) && ((char)*(ushort *)(iVar3 + 0x68) < '\0')) &&
         (iVar1 = FUN_004f8b10(param_1,iVar3), puVar2 = PTR_DAT_00802c54, iVar1 == 0)) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x7c;
    } while (iVar4 < *(int *)(puVar2 + 0x468c));
  }
  return 0;
}

