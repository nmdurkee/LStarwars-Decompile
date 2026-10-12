/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x6a03e0; label: FUN_006a03e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a03e0(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined1 *puVar5;
  int *unaff_EDI;
  
  iVar2 = FUN_006a3bb0(param_1,0x20);
  if (-1 < iVar2) {
    pvVar3 = _calloc(iVar2 + 1,1);
    unaff_EDI[3] = (int)pvVar3;
    FUN_0069fd80();
    iVar2 = FUN_006a3bb0(param_1,0x20);
    unaff_EDI[2] = iVar2;
    if (-1 < iVar2) {
      pvVar3 = _calloc(iVar2 + 1,4);
      *unaff_EDI = (int)pvVar3;
      pvVar3 = _calloc(unaff_EDI[2] + 1,4);
      iVar2 = 0;
      unaff_EDI[1] = (int)pvVar3;
      if (0 < unaff_EDI[2]) {
        do {
          iVar4 = FUN_006a3bb0(param_1,0x20);
          if (iVar4 < 0) goto LAB_006a04be;
          *(int *)(unaff_EDI[1] + iVar2 * 4) = iVar4;
          pvVar3 = _calloc(iVar4 + 1,1);
          *(void **)(*unaff_EDI + iVar2 * 4) = pvVar3;
          puVar5 = *(undefined1 **)(*unaff_EDI + iVar2 * 4);
          for (; iVar4 != 0; iVar4 = iVar4 + -1) {
            uVar1 = FUN_006a3bb0(param_1,8);
            *puVar5 = uVar1;
            puVar5 = puVar5 + 1;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < unaff_EDI[2]);
      }
      iVar2 = FUN_006a3bb0(param_1,1);
      if (iVar2 == 1) {
        return 0;
      }
    }
  }
LAB_006a04be:
  FUN_006a00b0();
  return 0xffffff7b;
}

