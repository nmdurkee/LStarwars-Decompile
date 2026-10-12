/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e5f10; label: FUN_004e5f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e5f10(int param_1)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (DAT_00951b50 == 0) {
    iVar4 = 0;
    piVar2 = &DAT_0088a418;
    while (*piVar2 != param_1) {
      piVar2 = piVar2 + 0xc;
      iVar4 = iVar4 + 1;
      if (0x88a4d7 < (int)piVar2) {
        return;
      }
    }
    FUN_00414c50(&DAT_0088a41c + iVar4 * 0x30);
    FUN_00590c10((&DAT_0088a414)[iVar4 * 0xc],0,0);
    uVar3 = FUN_00559f50(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00804e44,
                         (&DAT_0088a414)[iVar4 * 0xc],1,1);
    FUN_0055a250(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),uVar3);
    FUN_005900a0((&DAT_0088a414)[iVar4 * 0xc],1);
    puVar1 = PTR_DAT_00802c54;
    (&DAT_0088a43c)[iVar4 * 0x30] = 1;
    *(uint *)(*(int *)(puVar1 + 0x130) + 0x281c) =
         *(uint *)(*(int *)(puVar1 + 0x130) + 0x281c) | 1 << ((byte)iVar4 & 0x1f);
  }
  return;
}

