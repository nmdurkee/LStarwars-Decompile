/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x590530; label: FUN_00590530
 */

void FUN_00590530(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *param_2;
  if ((short)param_2[1] != 0) {
    iVar3 = 0;
    do {
      FUN_00590140(iVar4,param_1);
      if ((param_3 != 0) && (iVar3 < 0x40)) {
        iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        uVar5 = 1 << ((byte)iVar3 & 0x1f);
        *(byte *)(iVar4 + 0x6d) = -((*(uint *)(param_3 + iVar1 * 4) & uVar5) != 0) & 2;
        *(ushort *)(iVar4 + 0x7a) =
             *(ushort *)(iVar4 + 0x7a) ^
             (byte)(((*(uint *)(param_3 + 0x10 + iVar1 * 4) & uVar5) != 0) * '\x02' ^
                   *(byte *)(iVar4 + 0x7a)) & 2;
        uVar2 = (byte)((*(uint *)(param_3 + 8 + iVar1 * 4) & uVar5) != 0 ^
                      (byte)*(ushort *)(iVar4 + 0x7a)) & 1 ^ *(ushort *)(iVar4 + 0x7a);
        *(ushort *)(iVar4 + 0x7a) = uVar2;
        *(ushort *)(iVar4 + 0x7a) =
             ((ushort)((*(uint *)(param_3 + 0x18 + iVar1 * 4) & uVar5) != 0) * 0x200 ^ uVar2) &
             0x200 ^ uVar2;
        *(undefined1 *)(iVar4 + 0x6f) = *(undefined1 *)(iVar3 + 0x20 + param_3);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x7c;
    } while (iVar3 < (int)(uint)*(ushort *)(param_2 + 1));
  }
  return;
}

