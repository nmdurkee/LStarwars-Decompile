/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x5804f0; label: FUN_005804f0
 */

void FUN_005804f0(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((DAT_00951cd0 < 2) && (iVar3 = FUN_004f7fb0(param_1), iVar3 != 0)) {
    uVar2 = FUN_0062c3b0(*(undefined4 *)(DAT_00951cd4 + 0x134),*(undefined4 *)(param_1 + 0x510));
    *(undefined2 *)(DAT_00951cc0 + 0x30 + DAT_00951cd0 * 2) = uVar2;
    FUN_004f8100(param_1);
    uVar4 = FUN_006e6b90();
    uVar1 = (ushort)((int)uVar4 >> 0x1f);
    *(ushort *)(DAT_00951cc0 + 0x34 + DAT_00951cd0 * 2) = ((ushort)uVar4 ^ uVar1) - uVar1;
    DAT_00951cd0 = DAT_00951cd0 + 1;
  }
  return;
}

