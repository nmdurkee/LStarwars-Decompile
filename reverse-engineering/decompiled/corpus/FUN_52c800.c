/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52c800; label: FUN_0052c800
 */

void FUN_0052c800(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  float10 fVar3;
  
  iVar1 = param_3 + unaff_EDI * 0x14;
  if (*(char *)(param_3 + 0x39 + unaff_EDI * 0x14) != '\0') {
    if (*(char *)(iVar1 + 0x38) != '\0') {
      for (iVar2 = FUN_004f1460(param_1); iVar2 != 0; iVar2 = FUN_004f1460(param_1,iVar2)) {
        if ((*(byte *)(iVar2 + 0xe) & 8) != 0) {
          fVar3 = (float10)FUN_00514920(param_2,param_3,*(undefined4 *)(iVar2 + 0x10));
          *(float *)(param_3 + ((int)*(char *)(iVar2 + 0xd) + unaff_EDI * 5 + 10) * 4) =
               (float)fVar3;
        }
      }
    }
    *(undefined1 *)(iVar1 + 0x39) = 0;
  }
  return;
}

