/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d8510; label: FUN_004d8510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d8510(void)

{
  undefined4 *puVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_14;
  iVar6 = 0;
  DAT_00882414 = 0;
  if (DAT_00882a70 != 0) {
    _sprintf(local_14,"Sniper%d",DAT_00882a70);
    psVar3 = (short *)FUN_005d0690(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_14);
    if ((psVar3 != (short *)0x0) && (0 < *psVar3)) {
      iVar5 = 0;
      do {
        iVar2 = DAT_00882414;
        if (9 < DAT_00882414) break;
        iVar4 = *(int *)(psVar3 + 4) + iVar5;
        (&DAT_00882908)[DAT_00882414 * 8] = *(undefined4 *)(*(int *)(psVar3 + 4) + iVar5);
        (&DAT_0088290c)[iVar2 * 8] = *(undefined4 *)(iVar4 + 4);
        (&DAT_00882910)[iVar2 * 8] = *(undefined4 *)(iVar4 + 8);
        puVar1 = (undefined4 *)(*(int *)(psVar3 + 4) + 0xc + iVar5);
        (&DAT_00882914)[iVar2 * 8] = *puVar1;
        (&DAT_00882918)[iVar2 * 8] = puVar1[1];
        (&DAT_0088291c)[iVar2 * 8] = puVar1[2];
        fVar7 = (float10)FUN_005b9dd0();
        iVar6 = iVar6 + 2;
        iVar5 = iVar5 + 0x18;
        (&DAT_00882920)[iVar2 * 8] =
             (float)((float10)_DAT_007ffccc * (float10)0.5 + (float10)_DAT_007ffccc * fVar7);
        (&DAT_00882924)[iVar2 * 8] = 0;
        DAT_00882414 = DAT_00882414 + 1;
      } while (iVar6 < *psVar3);
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_14);
  return;
}

