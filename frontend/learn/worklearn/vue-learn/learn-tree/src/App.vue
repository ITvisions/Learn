<template>
  <div id="app">
  </div>
</template>

<script>

export default {
  name: 'App',
  data () {
    return {
      
    }
  },
  methods: {
    insert_sort(int* a,int len) {
      int temp,j;
      for(int i = 1 ; i < len ; i++) {
        temp = a[i];
        j = i + 1;
        while(j > 0 && a[j] < a[i]) {
          a[j+1] = a[j];
          j--;
        }
        a[j - 1] = temp;
        for(int m = 0 ; m < len ; m++) {
          printf("%d ",a[m]);
        }
        printf("\n");
      }
    }
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
