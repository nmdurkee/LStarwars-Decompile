/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5faaf0; label: FUN_005faaf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005faaf0(undefined4 param_1,byte param_2,undefined4 param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  uint *unaff_EDI;
  
  FUN_005e52d0(param_1);
  FUN_005e52f0(param_1);
  uVar2 = *unaff_EDI + 0xf & 0xfffffff0;
  *unaff_EDI = uVar2;
  *(uint *)(unaff_ESI + 0x48) = uVar2;
  *unaff_EDI = *unaff_EDI + 0x58;
  iVar3 = *(int *)(unaff_ESI + 0x48);
  *(int *)(unaff_ESI + 0x44) = iVar3;
  *(int *)(unaff_ESI + 0x2c) = iVar3 + 0x50;
  *(int *)(unaff_ESI + 0x30) = iVar3 + 0x54;
  iVar3 = FUN_005e4d20(1,param_3);
  *(int *)(unaff_ESI + 0x40) = iVar3;
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0x54) = 0x3f800000;
    *(undefined4 *)(*(int *)(unaff_ESI + 0x40) + 0x58) = 0x3f800000;
    *(undefined4 *)(*(int *)(unaff_ESI + 0x40) + 0x5c) = 0x3f800000;
    *(uint *)(*(int *)(unaff_ESI + 0x40) + 0x40) =
         *(uint *)(*(int *)(unaff_ESI + 0x40) + 0x40) & 0xffffefff | 0x2000;
    puVar1 = (uint *)(*(int *)(unaff_ESI + 0x40) + 0x40);
    *puVar1 = *puVar1 | 0xc000;
    *(undefined4 *)(*(int *)(unaff_ESI + 0x40) + 0x70) = 0x3f800000;
    *(uint *)(*(int *)(unaff_ESI + 0x40) + 0x40) =
         *(uint *)(*(int *)(unaff_ESI + 0x40) + 0x40) & 0xfffffff1 | 1;
    puVar1 = (uint *)(*(int *)(unaff_ESI + 0x40) + 0x40);
    *puVar1 = *puVar1 | 0x40000;
    *(short *)(*(int *)(unaff_ESI + 0x40) + 0x74) = (short)param_1;
    if ((param_2 & 8) == 0) {
      puVar1 = (uint *)(*(int *)(unaff_ESI + 0x40) + 0x44);
      *puVar1 = *puVar1 | 4;
    }
    else {
      puVar1 = (uint *)(*(int *)(unaff_ESI + 0x40) + 0x44);
      *puVar1 = *puVar1 & 0xfffffffb;
    }
    *(uint *)(*(int *)(unaff_ESI + 0x40) + 0x40) =
         *(uint *)(*(int *)(unaff_ESI + 0x40) + 0x40) & 0xfffeffff | 0x20000;
    iVar3 = *(int *)(unaff_ESI + 0x40);
    if ((param_2 & 2) == 0) {
      *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xfffffff1 | 1;
    }
    else {
      *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xfffffff0;
    }
    iVar3 = *(int *)(unaff_ESI + 0x40);
    if ((param_2 & 0x40) == 0) {
      if ((param_2 & 0x20) == 0) {
        *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) | 0xc000;
      }
      else {
        *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffff7fff | 0x4000;
      }
    }
    else {
      *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffff3fff;
    }
    iVar3 = *(int *)(unaff_ESI + 0x40);
    if ((param_2 & 4) == 0) {
      if ((param_2 & 0x10) == 0) {
        *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffffffcf;
      }
      else {
        *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffffffef | 0x20;
      }
    }
    else {
      *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffffffdf | 0x10;
    }
    FUN_005e4b00(*(undefined4 *)(unaff_ESI + 0x40));
    return 1;
  }
  return 0;
}

