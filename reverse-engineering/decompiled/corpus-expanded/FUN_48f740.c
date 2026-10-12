/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48f740; label: FUN_0048f740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048f740(int param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  iVar3 = 0;
  do {
    if (-1 < iVar5) {
      _memset((void *)(iVar3 + DAT_0087b2cc),0,0x2e28);
      *(undefined4 *)(iVar3 + 0x2820 + DAT_0087b2cc) = 0;
      *(undefined4 *)(iVar3 + 0x2814 + DAT_0087b2cc) = 0x49f42400;
    }
    FUN_00559af0(0,iVar5);
    FUN_005a0570(iVar5);
    iVar3 = iVar3 + 0x2e28;
    iVar5 = iVar5 + 1;
  } while (iVar3 < 0x229e0);
  DAT_0087aa8c = DAT_0086e4c4;
  if ((param_2 != 0) && (param_1 != -1)) {
    iVar3 = param_1 * 0xc;
    *(undefined4 *)(&DAT_0086e0f4 + iVar3) = *(undefined4 *)(&DAT_00875f4c + iVar3);
    *(undefined4 *)(&DAT_0086e0f8 + iVar3) = *(undefined4 *)(&DAT_00875f50 + iVar3);
    (&DAT_0086e0fc)[param_1 * 3] = *(undefined4 *)(&DAT_00875f54 + iVar3);
    iVar3 = param_1 * 0x9c + DAT_00951354;
    DAT_00951238 = 0;
    iVar5 = 0;
    if (*(char *)(iVar3 + 0x7d) != '\0') {
      psVar2 = (short *)(iVar3 + 0x60);
      do {
        puVar4 = (undefined4 *)(&DAT_0086e731 + *psVar2 * 0x54);
        puVar6 = (undefined4 *)(&DAT_008668d9 + *psVar2 * 0x54);
        for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar6 = puVar6 + 1;
        }
        iVar5 = iVar5 + 1;
        psVar2 = psVar2 + 1;
      } while (iVar5 < (int)(uint)*(byte *)(iVar3 + 0x7d));
    }
  }
  return;
}

