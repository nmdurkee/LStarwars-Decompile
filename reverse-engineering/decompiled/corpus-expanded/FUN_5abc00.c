/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5abc00; label: FUN_005abc00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005abc00(undefined4 param_1,int *param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = *param_2;
  if ((short)param_2[2] != 0) {
    iVar5 = 0;
    do {
      FUN_005aba50(param_1);
      if ((param_3 != 0) && (iVar5 < 0x40)) {
        iVar3 = (int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5;
        uVar7 = 1 << ((byte)iVar5 & 0x1f);
        *(ushort *)(iVar6 + 0x13a) =
             *(ushort *)(iVar6 + 0x13a) ^
             (byte)(((*(uint *)(param_3 + 8 + iVar3 * 4) & uVar7) != 0) * '\x04' ^
                   *(byte *)(iVar6 + 0x13a)) & 4;
        uVar4 = (byte)(((*(uint *)(param_3 + iVar3 * 4) & uVar7) != 0) * '\x02' ^
                      (byte)*(ushort *)(iVar6 + 0x13a)) & 2 ^ *(ushort *)(iVar6 + 0x13a);
        *(ushort *)(iVar6 + 0x13a) = uVar4;
        uVar4 = (byte)(((*(uint *)(param_3 + 0x10 + iVar3 * 4) & uVar7) != 0) * '\b' ^ (byte)uVar4)
                & 8 ^ uVar4;
        *(ushort *)(iVar6 + 0x13a) = uVar4;
        uVar4 = (byte)(((*(uint *)(param_3 + 0x18 + iVar3 * 4) & uVar7) != 0) * '\x10' ^ (byte)uVar4
                      ) & 0x10 ^ uVar4;
        *(ushort *)(iVar6 + 0x13a) = uVar4;
        uVar4 = (byte)(((*(uint *)(param_3 + 0x20 + iVar3 * 4) & uVar7) != 0) * ' ' ^ (byte)uVar4) &
                0x20 ^ uVar4;
        *(ushort *)(iVar6 + 0x13a) = uVar4;
        *(ushort *)(iVar6 + 0x13a) =
             ((ushort)((*(uint *)(param_3 + 0x28 + iVar3 * 4) & uVar7) != 0) * 0x400 ^ uVar4) &
             0x400 ^ uVar4;
        cVar1 = *(char *)(iVar5 + 0x30 + param_3);
        if (cVar1 != -1) {
          *(char *)(iVar6 + 0x12e) = cVar1;
        }
      }
      if (*(int *)(iVar6 + 0x18) != 0) {
        for (puVar2 = *(undefined4 **)(*(int *)(iVar6 + 0x18) + 0x18); puVar2 != (undefined4 *)0x0;
            puVar2 = (undefined4 *)*puVar2) {
          if (*(char *)(puVar2[9] + 1) == '\x03') {
            FUN_005cfc00(puVar2 + 1,*(byte *)(iVar6 + 0x13a) >> 5 & 1);
          }
        }
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x13c;
    } while (iVar5 < (int)(uint)*(ushort *)(param_2 + 2));
  }
  return;
}

