/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x540b10; label: FUN_00540b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00540b10(int *param_1,int param_2)

{
  int iVar1;
  ushort *puVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  DAT_009242c8 = 0;
  _DAT_009242cc = 0;
  uVar4 = 2;
  do {
    bVar3 = (byte)uVar4;
    if ((*(ushort *)(iVar5 + 0x68 + *param_1) & 0x100) == 0) {
      (&DAT_009242c8)[uVar4 - 2 >> 5] = (&DAT_009242c8)[uVar4 - 2 >> 5] | 1 << (bVar3 - 2 & 0x1f);
    }
    puVar2 = (ushort *)(iVar5 + 0x68 + *param_1);
    *puVar2 = *puVar2 | 0x100;
    if ((*(ushort *)(iVar5 + 0x1a4 + *param_1) & 0x100) == 0) {
      (&DAT_009242c8)[uVar4 - 1 >> 5] = (&DAT_009242c8)[uVar4 - 1 >> 5] | 1 << (bVar3 - 1 & 0x1f);
    }
    puVar2 = (ushort *)(iVar5 + 0x1a4 + *param_1);
    *puVar2 = *puVar2 | 0x100;
    if ((*(ushort *)(iVar5 + 0x2e0 + *param_1) & 0x100) == 0) {
      (&DAT_009242c8)[uVar4 >> 5] = (&DAT_009242c8)[uVar4 >> 5] | 1 << (bVar3 & 0x1f);
    }
    puVar2 = (ushort *)(iVar5 + 0x2e0 + *param_1);
    *puVar2 = *puVar2 | 0x100;
    if ((*(ushort *)(iVar5 + 0x41c + *param_1) & 0x100) == 0) {
      (&DAT_009242c8)[uVar4 + 1 >> 5] =
           (&DAT_009242c8)[uVar4 + 1 >> 5] | 1 << ((byte)(uVar4 + 1) & 0x1f);
    }
    puVar2 = (ushort *)(iVar5 + 0x41c + *param_1);
    *puVar2 = *puVar2 | 0x100;
    iVar1 = uVar4 + 2;
    iVar5 = iVar5 + 0x4f0;
    uVar4 = uVar4 + 4;
  } while (iVar1 < 0x40);
  iVar5 = *param_1;
  puVar2 = (ushort *)(param_2 * 0x13c + 0x68 + iVar5);
  *puVar2 = *puVar2 & 0xfeff;
  return param_2 * 0x13c + 0x68 + iVar5;
}

