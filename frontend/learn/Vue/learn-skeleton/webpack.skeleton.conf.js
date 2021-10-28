'use strict'
const path = require('path')
const nodeExternals = require('webpack-node-externals')
const VueSSRServerPlugin = require('vue-server-renderer/server-plugin')

module.exports = {
    target: 'node',
    devtool: '#source-map',
    entry: './src/skeleton/skeleton.entry.js',
    output: {
        path: path.resolve(__dirname, '../dist'),
        publicPath: '/dist/',
        filename: '[name].js',
        libraryTarget: 'commonjs2'
    },
    module: {
        noParse: /es6-promise\.js$/,  // avoid webpack shimming process
        rules: [
            {
                test: /\.vue$/,
                loader: 'vue-loader',
                options: {
                    compilerOptions: {
                        preserveWithspace: false
                    }
                }
            },
            {
                test: /\.css$/,
                use: ['vue-style-loader', 'css-loader']
            }
        ]
    },
    performance: {
        hints: false
    },
    externals: nodeExternals({
        whitelist: /\.css$/
    }),
    plugins: [
        new VueSSRServerPlugin({
            filename: 'skeleton.json'
        })
    ]
}