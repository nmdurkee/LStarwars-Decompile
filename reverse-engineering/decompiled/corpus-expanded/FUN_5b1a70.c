/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b1a70; label: FUN_005b1a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b1a70(undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(PTR_DAT_00802c54 + 0x46cc) < 0xc0) {
    FUN_005da860(&local_c,*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),param_1);
    iVar3 = FUN_005cfac0(&local_c);
    if (iVar3 != 0) {
      iVar2 = *(int *)(PTR_DAT_00802c54 + 0x46cc);
      iVar3 = *(int *)(PTR_DAT_00802c54 + 0x46d0);
      pbVar1 = (byte *)(iVar3 + iVar2 * 0x14);
      *pbVar1 = *pbVar1 & 0xf0;
      iVar3 = iVar3 + iVar2 * 0x14;
      *(undefined4 *)(iVar3 + 4) = local_c;
      *(undefined4 *)(iVar3 + 8) = local_8;
      *(undefined4 *)(iVar3 + 0xc) = local_4;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      *(undefined1 *)(iVar3 + 2) = 0;
      *(int *)(PTR_DAT_00802c54 + 0x46cc) = *(int *)(PTR_DAT_00802c54 + 0x46cc) + 1;
      return *(undefined4 *)(PTR_DAT_00802c54 + 0x46cc);
    }
  }
  return 0xffffffff;
}

