/* Ghidra analysis pseudocode, not original source.
 * ev_619d50b6392102a54c9e38c540a3f8930ee6fdfe94aeb342acdefb90820d232e
 * Entry: 0x59f4e0; label: FUN_0059f4e0
 */

void FUN_0059f4e0(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  char *pcVar6;
  int local_4;
  
  if (param_1 != (undefined4 *)0x0) {
    pcVar6 = (char *)param_1[2];
    *(undefined1 *)(param_1 + 3) = 0;
    FUN_0059f2a0(param_1);
    local_4 = 0;
    if (0 < (int)param_1[1]) {
      do {
        *(ushort *)(pcVar6 + 10) = *(ushort *)(pcVar6 + 10) & 0xffdf;
        uVar4 = *(ushort *)(pcVar6 + 10);
        pcVar6[8] = '\0';
        if ((param_2 == (int *)0x0) || (*param_2 == 0)) {
          *(ushort *)(pcVar6 + 10) = uVar4 & 0xfedd;
          if ((pcVar6[3] == '\x01') && (**(char **)(pcVar6 + 0xc) == '\x04')) {
            DAT_00956434 = DAT_00956434 + '\x01';
            cVar2 = FUN_0059da30(DAT_00956434);
            *(ushort *)(pcVar6 + 10) = *(ushort *)(pcVar6 + 10) | 0x400;
            pcVar6[1] = cVar2;
            if (*pcVar6 == cVar2) {
              *(ushort *)(pcVar6 + 10) = *(ushort *)(pcVar6 + 10) | 0x801;
            }
            else {
              *(ushort *)(pcVar6 + 10) = *(ushort *)(pcVar6 + 10) & 0xfffe;
            }
          }
          else {
            if (*pcVar6 == '\0') {
              uVar4 = uVar4 & 0xfedd | 1;
            }
            else {
              uVar4 = uVar4 & 0xfedc;
            }
            *(ushort *)(pcVar6 + 10) = uVar4;
          }
          if (((code *)(&PTR_LAB_00805514)[(uint)(byte)pcVar6[3] * 3] != (code *)0x0) &&
             ((*(ushort *)(pcVar6 + 10) & 0x1000) == 0)) {
            (*(code *)(&PTR_LAB_00805514)[(uint)(byte)pcVar6[3] * 3])(param_1,pcVar6);
          }
          if ((pcVar6[3] == '\0') &&
             ((((*(ushort *)(pcVar6 + 10) & 0x4000) == 0 && (DAT_0093b2a4 == 0)) ||
              (((*(ushort *)(pcVar6 + 10) & 0x2000) == 0 && (DAT_0093b2a4 != 0)))))) {
            piVar1 = *(int **)(pcVar6 + 0xc);
            iVar3 = 0;
            if (0 < *piVar1) {
              do {
                FUN_0055a2b0(*param_1,**(undefined4 **)(piVar1[2] + iVar3 * 4),0,1);
                iVar3 = iVar3 + 1;
              } while (iVar3 < *piVar1);
            }
          }
          else if ((((*(ushort *)(pcVar6 + 10) & 1) == 0) && ((*(ushort *)(pcVar6 + 10) & 4) != 0))
                  && (pcVar6[3] == '\0')) {
            piVar1 = *(int **)(pcVar6 + 0xc);
            iVar3 = 0;
            if (0 < *piVar1) {
              do {
                FUN_0055a2b0(*param_1,**(undefined4 **)(piVar1[2] + iVar3 * 4),0,1);
                iVar3 = iVar3 + 1;
              } while (iVar3 < *piVar1);
            }
          }
        }
        else {
          iVar3 = (int)(local_4 + (local_4 >> 0x1f & 0x1fU)) >> 5;
          uVar5 = 1 << ((byte)local_4 & 0x1f);
          uVar4 = (byte)((param_2[iVar3 + 1] & uVar5) != 0 ^ (byte)uVar4) & 1 ^ uVar4;
          *(ushort *)(pcVar6 + 10) = uVar4;
          uVar4 = (byte)(((param_2[iVar3 + 0x21] & uVar5) != 0) * '\x02' ^ (byte)uVar4) & 2 ^ uVar4;
          *(ushort *)(pcVar6 + 10) = uVar4;
          uVar4 = (byte)(((param_2[iVar3 + 0x31] & uVar5) != 0) * ' ' ^ (byte)uVar4) & 0x20 ^ uVar4;
          *(ushort *)(pcVar6 + 10) = uVar4;
          *(ushort *)(pcVar6 + 10) =
               ((ushort)((param_2[iVar3 + 0x41] & uVar5) != 0) * 0x400 ^ uVar4) & 0x400 ^ uVar4;
          if ((pcVar6[3] == '\x01') && (**(char **)(pcVar6 + 0xc) == '\x04')) {
            DAT_00956434 = DAT_00956434 + '\x01';
            cVar2 = FUN_0059da30(DAT_00956434);
            pcVar6[1] = cVar2;
          }
        }
        local_4 = local_4 + 1;
        pcVar6 = pcVar6 + 0x20;
      } while (local_4 < (int)param_1[1]);
    }
  }
  return;
}

