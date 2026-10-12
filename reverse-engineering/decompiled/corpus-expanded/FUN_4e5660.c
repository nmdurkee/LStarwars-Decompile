/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e5660; label: FUN_004e5660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004e5660(void)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  
  if ((((DAT_0087a96c != (int *)0x0) ||
       (DAT_0087a96c = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802f54,
                                           "bigbang1"), DAT_0087a96c != (int *)0x0)) &&
      (*DAT_0087a96c != 0)) &&
     ((uVar1 = *(uint *)(*DAT_0087a96c + 0x94), (uVar1 & 1) != 0 ||
      (((uVar1 & 0x800000) != 0 &&
       (((((DAT_0093d7f0 != 0 &&
           ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b1d4 ||
            (iVar3 = FUN_0054a240(DAT_0093d7f0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),
                                  *(undefined4 *)(PTR_DAT_00802c54 + 0x11c)), iVar3 == 0)))) &&
          (pcVar2 = *(char **)(DAT_0093d7f0 + 0xcc4), pcVar2 != (char *)0x0)) &&
         ((*pcVar2 != '\0' || ((pcVar2[1] & 2U) != 0)))) ||
        ((DAT_0093d7f4 != 0 &&
         ((((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b1d4 ||
            (iVar3 = FUN_0054a240(DAT_0093d7f4,*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),
                                  *(undefined4 *)(PTR_DAT_00802c54 + 0x11c)), iVar3 == 0)) &&
           (pcVar2 = *(char **)(DAT_0093d7f4 + 0xcc4), pcVar2 != (char *)0x0)) &&
          ((*pcVar2 != '\0' || ((pcVar2[1] & 2U) != 0)))))))))))))) {
    return 1;
  }
  return 0;
}

