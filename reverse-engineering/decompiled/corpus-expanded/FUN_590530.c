/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x590530; label: FUN_00590530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

