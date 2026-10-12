/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f29f0; label: FUN_004f29f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f29f0(char *param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar4 = 0;
  do {
    do {
      pcVar2 = param_1;
      cVar1 = *pcVar2;
      param_1 = pcVar2 + 1;
    } while (cVar1 == ' ');
  } while (cVar1 == '\t');
  if (cVar1 == '-') {
    iVar4 = -1;
  }
  else if (cVar1 != '+') goto LAB_004f2a1d;
  cVar1 = *param_1;
  param_1 = pcVar2 + 2;
LAB_004f2a1d:
  if (((param_3 == 0) && (param_3 = 10, cVar1 == '0')) && ((*param_1 == 'x' || (*param_1 == 'X'))))
  {
    cVar1 = param_1[1];
    param_1 = param_1 + 1;
    param_3 = 0x10;
  }
  do {
    bVar3 = cVar1 - 0x30;
    if (9 < bVar3) {
      if ((byte)(cVar1 + 0xbfU) < 0x1a) {
        bVar3 = cVar1 - 0x37;
      }
      else {
        if (0x19 < (byte)(cVar1 + 0x9fU)) {
LAB_004f2a81:
          if (param_2 != (undefined4 *)0x0) {
            *param_2 = param_1 + -1;
          }
          if (iVar4 == 0) {
            return iVar5;
          }
          return iVar4 * iVar5;
        }
        bVar3 = cVar1 + 0xa9;
      }
    }
    if (param_3 <= (char)bVar3) goto LAB_004f2a81;
    iVar5 = iVar5 * param_3 + (int)(char)bVar3;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while( true );
}

