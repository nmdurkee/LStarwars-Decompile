/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x42f4a0; label: FUN_0042f4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042f4a0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  FUN_00686750(PTR_DAT_008021b4 + 0x11c,0x42480000);
  piVar3 = &DAT_0093d7f0;
  do {
    iVar1 = *piVar3;
    if ((((((iVar1 != 0) && ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)) &&
          (*(char *)(iVar1 + 0x28b) == '\0')) &&
         ((*(float *)(iVar1 + 0x1018) <= 0.0 && (*(float *)(iVar1 + 0x1000) <= 0.0)))) &&
        (((*(uint *)(iVar1 + 0xef0) & 0x400000) == 0 &&
         ((iVar2 = FUN_0058b7f0(iVar1), iVar2 == 0 && (iVar2 = FUN_0055f1d0(iVar1), iVar2 == 0))))))
       && ((*(uint *)(*(int *)(*(int *)(iVar1 + 0x54) + 0x24) + 0x90) & 0x4008000) == 0)) {
      iVar2 = FUN_00659010(iVar1 + 0x80,*(undefined4 *)(iVar1 + 0xac),
                           *(undefined4 *)(iVar1 + 0x1004));
      if (iVar2 != -1) {
        FUN_00438230(0,iVar1,1,0,0,1);
      }
      iVar2 = FUN_00658cd0(iVar1 + 0x80,*(undefined4 *)(iVar1 + 0xac),
                           *(undefined4 *)(iVar1 + 0x1004));
      if (iVar2 != -1) {
        FUN_00438230(0,iVar1,1,0,0,1);
      }
    }
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0x93d810);
  return;
}

