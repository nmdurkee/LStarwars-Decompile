/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49dd10; label: FUN_0049dd10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049dd10(int param_1,int param_2,int param_3)

{
  char cVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  
  cVar1 = *(char *)(param_1 + 0x7b5);
  if (((cVar1 == '\x02') || (cVar1 == '\x19')) ||
     ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\x02' && (cVar1 == '\x01')))
     ) {
    fVar2 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar2;
    if (fVar2 <= 0.0) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    }
  }
  else if (cVar1 == '\0') {
    if (*(char *)(param_1 + 0x281) != '\0') {
      *(undefined4 *)(param_1 + 0x77c) = 0;
      if ((*(short *)(param_1 + 0x7aa) == 0x49) &&
         (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x128) != 0)) {
        *(undefined2 *)(param_1 + 0x7aa) = 0x4a;
        fVar4 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),0x4a,0,0,1);
        *(float *)(param_1 + 0x77c) = (float)fVar4;
        if (0.0 < (float)fVar4) {
          *(undefined1 *)(param_1 + 0x7b5) = 0x19;
        }
      }
      else {
        *(undefined2 *)(param_1 + 0x7aa) = 10;
        fVar4 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),10,0,0,1);
        *(float *)(param_1 + 0x77c) = (float)fVar4;
        if (0.0 < (float)fVar4) {
          *(undefined1 *)(param_1 + 0x7b5) = 2;
        }
      }
      if (*(float *)(param_1 + 0x77c) <= 0.0) {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        FUN_00548020(param_1,0,0);
        return;
      }
      FUN_0062e650(param_1 + 8,0xffffffff);
      FUN_00548020(param_1,0,0);
      return;
    }
  }
  else if (*(char *)(param_1 + 0xe32) == '\x01') {
    if (((param_2 != 0) || (param_3 != 0)) && (cVar1 == -1)) {
      FUN_0049dc60(param_1,param_3);
      return;
    }
  }
  else if (cVar1 == '\x13') {
    iVar3 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0);
    if ((iVar3 != 0) &&
       (fVar2 = *(float *)(param_1 + 0x77c) - _DAT_00925018, *(float *)(param_1 + 0x77c) = fVar2,
       fVar2 <= 0.0)) {
      FUN_0049dc10();
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      return;
    }
  }
  else if (((param_2 != 0) &&
           ((*(char *)(param_1 + 0x281) != '\0' || (0.0 < *(float *)(param_1 + 0xd24))))) &&
          (iVar3 = FUN_005620f0(param_1), iVar3 != 0)) {
    if (*(char *)(param_1 + 0x7b5) == '\x06') {
      FUN_0058d930(param_1,0);
    }
    else if (*(char *)(param_1 + 0x7b5) == '\a') {
      FUN_0058d480(param_1,0);
    }
    *(undefined2 *)(param_1 + 0x7aa) = 0x48;
    fVar4 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),0x48,0,0,1);
    *(float *)(param_1 + 0x77c) = (float)fVar4;
    if (0.0 < (float)fVar4) {
      *(undefined1 *)(param_1 + 0x7b5) = 0x13;
      *(undefined4 *)(param_1 + 0xdb4) = 0x49f42400;
      return;
    }
    FUN_0049dc10();
    *(undefined4 *)(param_1 + 0xdb4) = 0x49f42400;
    return;
  }
  return;
}

